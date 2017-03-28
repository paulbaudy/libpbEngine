#pragma once
#include <iostream>
#include <vector>


#include "Component.h"

class Scene;

class Object
{
private :
	std::string sName;
	bool bRender;
	bool bChild;



	std::vector<Component*> vComponents;
	std::vector<Object> vChilds;
	Object* oParent;
	Scene* sCurrentScene;

	
	void setIsChild(bool child);
	void setParent(Object *parent);
public:
	Object();
	Object(Scene* currentScene);
	Object(std::string ObjectName, Scene* currentScene);
	~Object();

	virtual void start();
	virtual void update();

	bool isChild();

	template <class T> void addComponent() {
		if (std::is_base_of<Component, T>()) {
			/* Initialize new component */
			T* cNewComponent = new T();
			cNewComponent->create();

			/* Add component to object array */
			vComponents.push_back(cNewComponent);

			if (std::is_same<T, MeshComponent>()) {
				MeshComponent *mNewMesh = dynamic_cast<MeshComponent *>(cNewComponent);
				if (NULL != mNewMesh)
				{
					sCurrentScene->addMeshComponent(mNewMesh);
				}
			}
		}
	}
	template <class T> void addChild();
};
