#ifndef LAYER_STACK_H
#define LAYER_STACK_H
#include "Division/Core.h"
#include "Layer.h"
#include <vector>
namespace Division
{

	class DIVISION_API LayerStack{
		std::vector<Layer*> _layers;
		unsigned int _layerInsertIndex = 0;
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return  _layers.begin(); }
		std::vector<Layer*>::iterator end() { return  _layers.end(); }
	};

}


#endif // !LAYER_STACK_H


