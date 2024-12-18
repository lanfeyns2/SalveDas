#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Core.h"

namespace SalveDas
{
	namespace Logging
	{
		enum LOGLEVELS
		{
			ERROR,WARN,INFO
		};

		struct Logger	
		{
			SALVE_DAS_API Logger(std::string loggerName);

			std::string name;

			template<typename T>
			void PrintMsg(T msg,unsigned int level);
		};

		SALVE_DAS_API void SetLogLevel(unsigned int logLevel);
		SALVE_DAS_API void NewLogger(std::string loggerName);
		
		template<typename T>
		SALVE_DAS_API void PrintLogger(std::string loggerName, T message,unsigned int level);
		
		extern unsigned int currentLogLevel = 2;

		std::vector<Logger> loggers;

		
		inline Logger::Logger(std::string loggerName)
			: name(loggerName)
		{

		}

		template<typename T>
		inline void Logger::PrintMsg(T msg, unsigned int level)
		{
			if (level == LOGLEVELS::ERROR)
			{
				std::cout << "\033[1;31m" << msg << "\033[0m" << std::endl;
			}
			else if (level == LOGLEVELS::WARN)
			{
				std::cout << "\033[33m" << msg << "\033[0m" << std::endl;
			}
			else
			{
				std::cout << "\033[37m" << msg << "\033[0m" << std::endl;
			}
		}

		inline void SetLogLevel(unsigned int logLevel)
		{
			currentLogLevel = logLevel;
		}
		inline void NewLogger(std::string loggerName)
		{
			loggers.emplace_back(loggerName);
		}

		template<typename T>
		inline void PrintLogger(std::string loggerName, T message, unsigned int level)
		{
			if (level <= currentLogLevel)
			{
				for (auto logger : loggers)
				{
					if (logger.name == loggerName)
					{
						logger.PrintMsg(message, level);
						break;
					}
				}
			}
		}


	}
}