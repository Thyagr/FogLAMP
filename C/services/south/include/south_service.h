#ifndef _SOUTH_SERVICE_H
#define _SOUTH_SERVICE_H
/*
 * FogLAMP south service.
 *
 * Copyright (c) 2018 OSisoft, LLC
 *
 * Released under the Apache 2.0 Licence
 *
 * Author: Mark Riddoch
 */

#include <logger.h>
#include <south_plugin.h>
#include <service_handler.h>

#define SERVICE_NAME  "FogLAMP South"

/**
 * The SouthService class. This class is the core
 * of the service that provides south side services
 * to FogLAMP.
 */
class SouthService : public ServiceHandler {
	public:
		SouthService(const std::string& name);
		void 			start(std::string& coreAddress, unsigned short corePort);
		void 			stop();
		void			shutdown();
		void			configChange(const std::string&, const std::string&);
	private:
		SouthPlugin		*southPlugin;
		const std::string&	m_name;
		bool 			loadPlugin();
		Logger        		*logger;
		bool			m_shutdown;
};
#endif
