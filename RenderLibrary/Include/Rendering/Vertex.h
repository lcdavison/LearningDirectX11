#pragma once

#include <DirectXMath.h>

using namespace DirectX;

namespace RenderLibrary::Rendering
{
	struct Vertex
	{
		XMFLOAT4 position;
		XMFLOAT3 normal;
		XMFLOAT2 textureCoordinates;
	};
}