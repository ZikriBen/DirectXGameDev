#pragma once
#include <d3d11.h>

class GraphicsEngine
{
public:
	GraphicsEngine();
	~GraphicsEngine();
	bool init();
	bool release();
public:
	static GraphicsEngine* get();
private:
	ID3D11Device* m_d3dDevice;
	D3D_FEATURE_LEVEL m_featureLevel;
	ID3D11DeviceContext *m_immContext;
};
