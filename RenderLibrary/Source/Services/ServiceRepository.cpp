#include "Services/ServiceRepository.h"

namespace RenderLibrary
{
	namespace Services
	{
		std::unordered_map<ServiceID, std::shared_ptr<Service>> ServiceRepository::services_;

		void ServiceRepository::StopService(ServiceID serviceId)
		{
			auto iterator = services_.find(serviceId);

			auto service = iterator->second;
			service->Stop();

			services_.erase(iterator);
		}

		int ServiceRepository::GetServiceCount()
		{
			return services_.size();
		}
	}
}