#include "dpch.h"
#include "LayerStack.h"

namespace Division 
{
	LayerStack::LayerStack()
	{
		_layerInsert = _layers.begin();
	}
	LayerStack::~LayerStack() {
		for (Layer* layer : _layers) {
			if (layer != nullptr) {
				delete layer;
				layer = nullptr;
			}
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		_layerInsert = _layers.emplace(_layerInsert, layer);
		layer->OnAttach();
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		 _layers.emplace_back(overlay);
		 overlay->OnAttach();
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(_layers.begin(), _layers.end(), layer);
		if (it != _layers.end()) {
			_layers.erase(it);
			_layerInsert--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(_layers.begin(), _layers.end(), overlay);
		if (it != _layers.end()) {
			_layers.erase(it);
		}
	}


}
