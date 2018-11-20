//Windows Audio Capture (WAC) by KwstasG (Kostas Giannakakis)
#include "AudioCaptureWorker.h"
#include <iostream>

FAudioCaptureWorker* FAudioCaptureWorker::Runnable = NULL;
INT32 FAudioCaptureWorker::ThreadCounter = 0;

FAudioCaptureWorker::FAudioCaptureWorker() : m_sink(), m_listener(16, WAVE_FORMAT_PCM, 4, 0), Thread(NULL)
{
	// Higher overall ThreadCounter to avoid duplicated names
	FAudioCaptureWorker::ThreadCounter++;

	std::cout << "Initializing AudioCapture worker" << std::endl;
	//Thread = FRunnableThread::Create(this, *FString::Printf(TEXT("FAudioCaptureWorker%d"), FAudioCaptureWorker::ThreadCounter), 0, EThreadPriority::TPri_Normal);
}

FAudioCaptureWorker::~FAudioCaptureWorker()
{
	// Make sure to mark Thread as finished
	bIsFinished = true;

	//delete Thread;
	//Thread = NULL;
}

FAudioCaptureWorker* FAudioCaptureWorker::InitializeWorker()
{
	Runnable = new FAudioCaptureWorker();

	return Runnable;
}


bool FAudioCaptureWorker::Init()
{
	// Make sure the Worker is marked is not finished
	bIsFinished = false;

	return true;
}


UINT32 FAudioCaptureWorker::Run()
{
	m_listener.RecordAudioStream(&m_sink, bIsFinished);

	return 0;
}

void FAudioCaptureWorker::ShutdownWorker()
{
	//if (Runnable)
	//{
	//	Runnable->EnsureCompletion();
	//	delete Runnable;
	//	Runnable = NULL;
	//}
	std::cout << "Shutdown AudioCapture worker" << std::endl;
}


void FAudioCaptureWorker::Exit()
{
	// Make sure to mark Thread as finished
	bIsFinished = true;
}

void FAudioCaptureWorker::EnsureCompletion()
{
	// Make sure to mark Thread as finished
	bIsFinished = true;

	if (Thread != NULL)
	{
		//Thread->WaitForCompletion();
	}
}




