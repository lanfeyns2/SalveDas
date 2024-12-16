#include "LayerStack.h"

namespace SalveDas
{
	LayerStack::LayerStack()
	{
	}
	LayerStack::~LayerStack()
	{
		for (auto currentLayer : m_layers)
			delete currentLayer;
	}
	void LayerStack::PushLayer(SalveDas::Layer* layer)
	{
		m_layers.push_back(layer);
	}
	void LayerStack::DisableLayer(std::string layerName)
	{
		for (auto currentLayer : m_layers)
		{
			currentLayer->Disable();
		}
	}
	void LayerStack::EnableLayer(std::string layerName)
	{
		for (auto currentLayer : m_layers)
		{
			currentLayer->Enable();
		}
	}
	void LayerStack::RenderStack()
	{
		for (auto currentLayer : m_layers)
		{
			if (currentLayer->Visibility() == true)
				currentLayer->Update();
		}
	}
}