/****************************************************************************************** 
 *	Chili DirectX Framework Sound Pack Version 16.11.11									  *	
 *	Sound.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with this source code.  If not, see <http://www.gnu.org/licenses/>.			  *
 ******************************************************************************************/
#pragma once

#define HAVE_STRUCT_TIMESPEC
#include "ChiliWin.h"
#include <stdbool.h>
#include <pthread.h>
#include "SoundVector.h"
#pragma comment(lib, "pthreadVC2.lib")

//#include <memory>
//#include <vector>
//#include <mutex>
//#include <condition_variable>
//#include <thread>
//#include "ChiliException.h"
//#include <wrl\client.h>

#define COMPLETE 0
#if COMPLETE
// forward declare WAVEFORMATEX so we don't have to include bullshit headers
typedef struct tWAVEFORMATEX WAVEFORMATEX;



#pragma region Sound
#ifdef __cplusplus
class Sound
{
	friend SoundSystem::Channel;
public:
#endif // __cplusplus
#pragma region EnumLoopType
#ifdef __cplusplus
	enum class LoopType
	{
		NotLooping,
		AutoEmbeddedCuePoints,
		AutoFullSound,
		ManualFloat,
		ManualSample,
		Invalid
	};
#else
	typedef enum _LoopType
	{
		NotLooping,
		AutoEmbeddedCuePoints,
		AutoFullSound,
		ManualFloat,
		ManualSample,
		Invalid
	}LoopType;

#endif // __cplusplus
#pragma endregion // EnumLoopType
#ifdef __cplusplus
public:
	Sound() = default;
	// for backwards compatibility--2nd parameter false -> NotLooping
	Sound( const std::wstring& fileName, bool loopingWithAutoCueDetect );
	// do not pass this function Manual LoopTypes!
	Sound( const std::wstring& fileName, LoopType loopType = LoopType::NotLooping );
	Sound( const std::wstring& fileName, unsigned int loopStart, unsigned int loopEnd );
	Sound( const std::wstring& fileName, float loopStart, float loopEnd );
	Sound( Sound&& donor );
	Sound& operator=( Sound&& donor );
	void Play( float freqMod = 1.0f, float vol = 1.0f );
	void StopOne();
	void StopAll();
	~Sound();
private:
	Sound( const std::wstring& fileName, LoopType loopType,
		   unsigned int loopStartSample, unsigned int loopEndSample,
		   float loopStartSeconds, float loopEndSeconds );
private:
	UINT32 nBytes = 0u;
	bool looping = false;
	unsigned int loopStart;
	unsigned int loopEnd;
	std::unique_ptr<BYTE[]> pData;
	std::mutex mutex;
	std::condition_variable cvDeath;
	std::vector<SoundSystem::Channel*> activeChannelPtrs;
	static constexpr unsigned int nullSample = 0xFFFFFFFFu;
	static constexpr float nullSeconds = -1.0f;
};
#else
	extern const unsigned int Sound_nullSample;
	extern const float Sound_nullSeconds;

	typedef struct _Sound
	{
		UINT32 nBytes;
		bool looping;
		unsigned int loopStart;
		unsigned int loopEnd;
		pthread_mutex_t pMutex;
		BYTE *pData;
		pthread_cond_t cvDeath;
		ChannelVector activeChannelPtrs;
	}Sound;

	// for backwards compatibility--2nd parameter false -> NotLooping
	Sound Sound_CreateAutoCueDetect( const wchar_t* fileName, bool loopingWithAutoCueDetect );
	// do not pass this function Manual LoopTypes!
	Sound Sound_CreateNoLooping( const wchar_t* fileName, LoopType loopType );
	Sound Sound_CreateSampleRangeLoop( const wchar_t* fileName, unsigned int loopStart, unsigned int loopEnd );
	Sound Sound_CreateTimeRangeLoop( const wchar_t* fileName, float loopStart, float loopEnd );

	// Defaults: float freqMod = 1.0f, float vol = 1.0f 
	void Sound_Play( Sound *pSound, float freqMod, float vol );
	void Sound_StopOne( Sound *pSound );
	void Sound_StopAll( Sound *pSound );
	void Sound_Destroy( Sound *pSound );

#endif // __cplusplus__
#pragma endregion // Sound

#pragma region XAudioDll_C
typedef enum _SoundSystemLoadType
{
	SoundSystemLoadFolder,
	SoundSystemLoadLocal,
	SoundSystemLoadSystem,
	SoundSystemLoadInvalid
}SoundSystemLoadType;

typedef struct _XAudioDll
{
	HMODULE hModule;
}XAudioDll;

extern const wchar_t* XA_SystemPath;
extern const wchar_t* XA_FolderPath;
extern const wchar_t* XA_LocalPath;

XAudioDll XA_Create();
void XA_Destroy( XAudioDll *pXAudioDll );
HMODULE XA_GetModule( XAudioDll *pXAudioDll );
const wchar_t* XA_GetDllPath( XAudioDll *pXAudioDll, SoundSystemLoadType Type );
#pragma endregion // XAudioDll_C

#pragma region SoundSystem
#ifdef __cplusplus
class SoundSystem
{	
private:
#endif // __cplusplus

#pragma region XAudioDll
#ifdef __cplusplus__
	class XAudioDll
	{
	private:
#endif // __cplusplus__

#pragma region EnumLoadType
#ifdef __cplusplus__
		enum class LoadType
		{
			Folder,
			Local,
			System,
			Invalid
		};
#endif // __cplusplus__
#pragma endregion // EnumLoadType

#ifdef __cplusplus__
	public:
		XAudioDll();
		~XAudioDll();
		operator HMODULE() const;
	private:
		static const wchar_t* GetDllPath( LoadType type );
	private:
		HMODULE hModule = 0;
		static constexpr wchar_t* systemPath = L"XAudio2_7.dll";
#ifdef _M_X64
		static constexpr wchar_t* folderPath = L"XAudio\\XAudio2_7_64.dll";
		static constexpr wchar_t* localPath = L"XAudio2_7_64.dll";
#else
		static constexpr wchar_t* folderPath = L"XAudio\\XAudio2_7_32.dll";
		static constexpr wchar_t* localPath = L"XAudio2_7_32.dll";
#endif
	};
#endif // __cplusplus__
#pragma endregion // XAudioDll

#ifdef __cplusplus
public:
#endif // __cplusplus

#pragma region Channel
#ifdef __cplusplus__
	class Channel
	{
		friend class Sound;
	public:
		Channel( SoundSystem& sys );
		Channel( const Channel& ) = delete;
		~Channel();
		void PlaySoundBuffer( class Sound& s,float freqMod,float vol );
		void Stop();
	private:
		void RetargetSound( const Sound* pOld,Sound* pNew );
	private:
		std::unique_ptr<struct XAUDIO2_BUFFER> xaBuffer;
		struct IXAudio2SourceVoice* pSource = nullptr;
		class Sound* pSound = nullptr;
	};
#else
	typedef struct _Channel
	{
		struct XAUDIO2_BUFFER *xaBuffer;
		struct IXAudio2SourceVoice* pSource;
		Sound* pSound;
	}Channel;

	Channel Channel_Create( struct SoundSystem* sys );
	void Channel_Destroy( Channel *pChan );
	void Channel_PlaySoundBuffer( Channel *pChan, struct Sound *pSound, float freqMod, float vol );
	void Channel_Stop( Channel *pChan );
	void Channel_RetargetSound( Channel *pChan, struct Sound *pSound_Old, struct Sound *pSound_New );
#endif // __cplusplus__
#pragma endregion // Channel

#ifdef __cplusplus
public:
	SoundSystem( const SoundSystem& ) = delete;
	static SoundSystem& Get();
	static void SetMasterVolume( float vol = 1.0f );
	static const WAVEFORMATEX& GetFormat();
	void PlaySoundBuffer( class Sound& s,float freqMod,float vol );
private:
	SoundSystem();
	void DeactivateChannel( Channel& channel );
private:
	XAudioDll xaudio_dll;
	Microsoft::WRL::ComPtr<struct IXAudio2> pEngine;
	struct IXAudio2MasteringVoice* pMaster = nullptr;
	std::unique_ptr<WAVEFORMATEX> format;
	std::mutex mutex;
	std::vector<std::unique_ptr<Channel>> idleChannelPtrs;
	std::vector<std::unique_ptr<Channel>> activeChannelPtrs;
private:
	// change these values to match the format of the wav files you are loading
	// all wav files must have the same format!! (no mixing and matching)
	static constexpr WORD nChannelsPerSound = 2u;
	static constexpr DWORD nSamplesPerSec = 44100u;
	static constexpr WORD nBitsPerSample = 16u;
	// change this value to increase/decrease the maximum polyphony	
	static constexpr size_t nChannels = 64u;
};
#endif // __cplusplus
#pragma endregion // SoundSystem
#endif // COMPLETE