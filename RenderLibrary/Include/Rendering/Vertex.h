#pragma once

#include <DirectXMath.h>

namespace RenderLibrary::Rendering
{
	struct Vertex
	{
		DirectX::XMFLOAT4 position;
		DirectX::XMFLOAT3 normal;
		DirectX::XMFLOAT2 textureCoordinates;
	};
}