#pragma once

#include "Service.h"
#include "ServiceID.h"
#include "Exceptions/Exception.h"

#include <unordered_map>
#include <memory>

namespace RenderLibrary
{
	namespace Services
	{
		class ServiceRepository final
		{
			static std::unordered_map<ServiceID, std::shared_ptr<Service>> services_;

		public:

			template <class T>
			static void StartService();

			static void StopService(ServiceID serviceId);

			template <class T>
			static std::shared_ptr<T> GetService(ServiceID serviceId);
			
			static int GetServiceCount();
		};

		template <class T>
		void ServiceRepository::StartService()
		{
			std::shared_ptr<Service> service = std::make_shared<T>();

			auto serviceId = service->GetServiceID();

			if (serviceId == ServiceID::Unassigned)
			{
				throw Exception(L"Cannot start service with ID Unassigned");
			}
			else
			{
				service->Start();

				services_.insert({serviceId, service});
			}
		}

		template <class T>
		std::shared_ptr<T> ServiceRepository::GetService(ServiceID serviceId)
		{
			auto service = services_.at(serviceId);

			return std::dynamic_pointer_cast<T>(service);
		}
	}
}