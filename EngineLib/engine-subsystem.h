#pragma once



class EngineSubsystem
{
public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void ShutDown() = 0;
};