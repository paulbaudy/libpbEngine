#pragma once
#include <iostream>
#include <vector>
#include <map>

#include "glm.hpp"
#include "Component.h"

class Scene;

class Object
{
private :
	std::string sName;
	bool bRender;
	bool bChild;

	/* Object components */
	std::vector<Component*> vComponents;
	/* Components by component ID */
	std::map<int, Component*> mComponents;
	/* Object childs */
	std::vector<Object> vChilds;

	/* Parent object if current object is a child */
	Object* oParent;

	/* Current rendered scene */
	Scene* sCurrentScene;

	
	void setIsChild(bool child);
	void setParent(Object *parent);
public:
	Object();
	Object(Scene* currentScene);
	Object(std::string ObjectName, Scene* currentScene);
	~Object();

	virtual void start();
	virtual void update(float DeltaTime);

	bool isChild();

	/* Components functions */
	Component* getComponent(int componentID);

	template <class T> Component* addComponent() {
		if (std::is_base_of<Component, T>()) {
			/* Initialize new component */
			T* cNewComponent = new T();
			cNewComponent->setOwner(this);
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
			else if (std::is_same<T, CameraComponent>()) {
				CameraComponent *mNewCamera = dynamic_cast<CameraComponent *>(cNewComponent);
				if (NULL != mNewCamera)
				{
					Scene::cCurrentCamera = mNewCamera;
				}
				
			}

			mComponents.insert(std::pair<int, Component*>(cNewComponent->getComponentID(), cNewComponent));
			return cNewComponent;
		}
		return nullptr;
	}
};
