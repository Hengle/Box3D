/*
* Copyright (c) 2006-2009 Erin Catto http://www.box2d.org
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

#ifndef b3_CONTACT_MANAGER_H
#define b3_CONTACT_MANAGER_H

#include "Box3D/Collision/b3BroadPhase.h"

class b3Contact;
class b3ContactFilter;
class b3ContactListener;
class b3BlockAllocator;

// Delegate of b3World.
class b3ContactManager
{
public:
	b3ContactManager();

	// Broad-phase callback.
	void AddPair(void* proxyUserDataA, void* proxyUserDataB);

	void FindNewContacts();

	void Destroy(b3Contact* c);

	void Collide();
            
	b3BroadPhase m_broadPhase;
	b3Contact* m_contactList;
	int32 m_contactCount;
	b3ContactFilter* m_contactFilter;
	b3ContactListener* m_contactListener;
	b3BlockAllocator* m_allocator;
};

#endif
