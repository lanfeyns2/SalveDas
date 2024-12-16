#pragma once
#include "Layers/Layer.h"
#include <string>
#include <vector>
#include "Core.h"

namespace SalveDas
{
	class LayerStack
	{
	public:
		SALVE_DAS_API LayerStack();
		SALVE_DAS_API ~LayerStack();

		SALVE_DAS_API void PushLayer(SalveDas::Layer* layer);
		SALVE_DAS_API void DisableLayer(std::string layerName);
		SALVE_DAS_API void EnableLayer(std::string layerName);
		SALVE_DAS_API void RenderStack();

	private:
		std::vector<SalveDas::Layer*> m_layers;
	};
}

