#pragma once
#include <string>
#include <vector>

namespace SalveDas
{
	class Scene
	{
	public:
		Scene() {};
		~Scene() {};
		std::string name;
		std::vector<int> objects;

		void AddScene();
	};
}