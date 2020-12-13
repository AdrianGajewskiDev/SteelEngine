#pragma once
#include <string>

namespace Steel {
	namespace Graphics {

		struct WindowProps 
		{
			std::string Title;
			int Width;
			int Height;

			WindowProps() = default;

			WindowProps(const std::string title, int width, int height)
			{
				Title = title;
				Width = width;
				Height = height;
			}

		};

	}
}