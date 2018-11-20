#pragma once

#include "AudioSink.h"
#include "AudioListener.h"
#include <thread>


class FAudioCaptureWorker
{

public:

	//Singleton instance, can access the thread any time via static accessor, if it is active! 
	static FAudioCaptureWorker* Runnable;

	//Thread to run the worker FRunnable on 
	std::thread* Thread;

private:

	// Bool to check if the thread is running
	bool bIsFinished;

	// Counter for the ThreadNames
	static INT32 ThreadCounter;

	AudioListener	m_listener;
	AudioSink		m_sink;

protected:


public:

	//Constructor / Destructor
	FAudioCaptureWorker();
	~FAudioCaptureWorker();

	// Custom Init function
	static FAudioCaptureWorker* InitializeWorker();

	// Custom Shutdown function
	static void ShutdownWorker();

	// Start FRunnable Interface
	virtual bool Init();
	virtual UINT32 Run();
	virtual void Exit();
	// End FRunnable Interface

	// Make sure Thread completed
	void EnsureCompletion();

	bool IsFinished() const
	{
		return bIsFinished;
	}
};