//__________________________ Banshee Project - A modern game development toolkit _________________________________//
//_____________________________________ www.banshee-project.com __________________________________________________//
//________________________ Copyright (c) 2014 Marko Pintera. All rights reserved. ________________________________//
#include "BsGUIMouseEvent.h"

namespace BansheeEngine
{
	GUIMouseEvent::GUIMouseEvent()
		:mType(GUIMouseEventType::MouseMove), mButton(GUIMouseButton::Left), 
		mShift(false), mCtrl(false), mAlt(false), mWheelScrollAmount(0.0f)
	{

	}

	GUIMouseEvent::GUIMouseEvent(bool buttonStates[(int)GUIMouseButton::Count], bool shift, bool ctrl, bool alt)
		:mType(GUIMouseEventType::MouseMove), mButton(GUIMouseButton::Left),
		mShift(shift), mCtrl(ctrl), mAlt(alt)
	{
		memcpy(mButtonStates, buttonStates, sizeof(mButtonStates));
	}

	void GUIMouseEvent::setMouseOverData(const Vector2I& position)
	{
		mType = GUIMouseEventType::MouseOver;
		mPosition = position;
		mButton = GUIMouseButton::Left;
		mDragAmount = Vector2I();
		mWheelScrollAmount = 0.0f;
	}

	void GUIMouseEvent::setMouseOutData(const Vector2I& position)
	{
		mType = GUIMouseEventType::MouseOut;
		mPosition = position;
		mButton = GUIMouseButton::Left;
		mDragAmount = Vector2I();
		mWheelScrollAmount = 0.0f;
	}

	void GUIMouseEvent::setMouseMoveData(const Vector2I& position)
	{
		mType = GUIMouseEventType::MouseMove;
		mPosition = position;
		mButton = GUIMouseButton::Left;
		mDragAmount = Vector2I();
		mWheelScrollAmount = 0.0f;
	}

	void GUIMouseEvent::setMouseWheelScrollData(float scrollAmount)
	{
		mType = GUIMouseEventType::MouseWheelScroll;
		mPosition = Vector2I();
		mButton = GUIMouseButton::Left;
		mDragAmount = Vector2I();
		mWheelScrollAmount = scrollAmount;
	}

	void GUIMouseEvent::setMouseUpData(const Vector2I& position, GUIMouseButton button)
	{
		mType = GUIMouseEventType::MouseUp;
		mPosition = position;
		mButton = button;
		mDragAmount = Vector2I();
		mWheelScrollAmount = 0.0f;
	}

	void GUIMouseEvent::setMouseDownData(const Vector2I& position, GUIMouseButton button)
	{
		mType = GUIMouseEventType::MouseDown;
		mPosition = position;
		mButton = button;
		mDragAmount = Vector2I();
		mWheelScrollAmount = 0.0f;
	}

	void GUIMouseEvent::setMouseDoubleClickData(const Vector2I& position, GUIMouseButton button)
	{
		mType = GUIMouseEventType::MouseDoubleClick;
		mPosition = position;
		mButton = button;
		mDragAmount = Vector2I();
		mWheelScrollAmount = 0.0f;
	}

	void GUIMouseEvent::setMouseDragData(const Vector2I& position, const Vector2I& dragAmount)
	{
		mType = GUIMouseEventType::MouseDrag;
		mPosition = position;
		mButton = GUIMouseButton::Left;
		mDragAmount = dragAmount;
		mWheelScrollAmount = 0.0f;
	}

	void GUIMouseEvent::setMouseDragStartData(const Vector2I& position)
	{
		mType = GUIMouseEventType::MouseDragStart;
		mPosition = position;
		mButton = GUIMouseButton::Left;
		mDragAmount = Vector2I();
		mWheelScrollAmount = 0.0f;
	}

	void GUIMouseEvent::setMouseDragEndData(const Vector2I& position)
	{
		mType = GUIMouseEventType::MouseDragEnd;
		mPosition = position;
		mButton = GUIMouseButton::Left;
		mDragAmount = Vector2I();
		mWheelScrollAmount = 0.0f;
	}

	void GUIMouseEvent::setDragAndDropDroppedData(const Vector2I& position, UINT32 dragTypeId, void* dragData)
	{
		mType = GUIMouseEventType::MouseDragAndDropDropped;
		mPosition = position;
		mButton = GUIMouseButton::Left;
		mDragAmount = Vector2I();
		mWheelScrollAmount = 0.0f;
		mDragTypeId = dragTypeId;
		mDragData = dragData;
	}

	void GUIMouseEvent::setDragAndDropDraggedData(const Vector2I& position, UINT32 dragTypeId, void* dragData)
	{
		mType = GUIMouseEventType::MouseDragAndDropDragged;
		mPosition = position;
		mButton = GUIMouseButton::Left;
		mDragAmount = Vector2I();
		mWheelScrollAmount = 0.0f;
		mDragTypeId = dragTypeId;
		mDragData = dragData;
	}
}