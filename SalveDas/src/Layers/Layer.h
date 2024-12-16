#pragma once

namespace SalveDas
{
	class Layer
	{
	public:

		virtual void Update() {};


		bool Visibility() { return m_Visibility; };
		void Enable() {} ;
		void Disable() {};
	private:
		bool m_Visibility = true;
	};
}