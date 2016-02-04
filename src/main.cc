#include "CDK\window2.h"
#include "CDK\camera.h"
#include "CDK\drawable.h"
#include "CDK\geometry.h"
#include "CDK\material.h"
#include "CDK\loader.h"
#include <memory>
#include "CDK\types.h"
#include "CDK\node.h"
#include "CDK\input.h"
struct{
	std::shared_ptr<Node> root_node;
	std::shared_ptr<Camera> camera;

}Scene;
int Window::main(int argv, char** argc){
	
	std::shared_ptr<Window> window = std::make_shared<Window>();
	window->init(1024, 768);
	
	std::shared_ptr<Loader> loader = std::make_shared<Loader>();

	std::shared_ptr<Drawable> drawable = std::make_shared<Drawable>();

	//initialize
	drawable = loader->loadCDK("paris.cdk");
	Scene.root_node = std::make_shared<Node>();
	//Camera
	 Scene.camera = std::make_shared<Camera>();
	Scene.camera->setPosition(vec3(0.0, 0.0, 120.0));
	Scene.camera->setFront(vec3(0.0, 0.0, -120.0));
	Scene.camera->setPerspective(45, 800.0 / 600.0, 0.1, 100000.0);

	Scene.root_node->addChild(std::move(drawable));

	//drawable.reset();

	while (window->processEvents())
	{
		if (Input::pressKeyA()){
			Scene.root_node->removeChild(0);
		}
		Scene.camera->FpsCameraUpdate();
		window->clearScreen(vec3(0.3f, 0.2f, 0.7f));
		Scene.camera->render(Scene.root_node);
		window->swap();
	}

	return 0;

}