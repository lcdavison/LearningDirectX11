#include "Services/TestService.h"

using namespace RenderLibrary::Services;

TestService::TestService()
{
	serviceId = ServiceID::Test;
}

void TestService::Start()
{
	OutputDebugString(L"Started Test Service");
}

void TestService::Stop()
{
	OutputDebugString(L"Stopped Test Service");
}