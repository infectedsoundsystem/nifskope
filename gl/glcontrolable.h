/***** BEGIN LICENSE BLOCK *****

BSD License

Copyright (c) 2005-2010, NIF File Format Library and Tools
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The name of the NIF File Format Library and Tools project may not be
   used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

***** END LICENCE BLOCK *****/

#ifndef GLCONTROLABLE_H
#define GLCONTROLABLE_H

#include "../nifmodel.h"

class Controller;

class Scene;

//! Anything capable of having a Controller
class Controllable : public QObject
{
public:
	Controllable( Scene * Scene, const QModelIndex & index );
	virtual ~Controllable();
	
	QModelIndex index() const { return iBlock; }
	virtual bool isValid() const { return iBlock.isValid(); }
	
	virtual void clear();
	virtual void update( const NifModel * nif, const QModelIndex & index );
	
	virtual void transform();
	
	virtual void timeBounds( float & start, float & stop );
	
	void setSequence( const QString & seqname );
	Controller * findController( const QString & ctrltype, const QString & var1, const QString & var2 );
	
protected:
	//! Sets the Controller
	virtual void setController( const NifModel * nif, const QModelIndex & iController ) { Q_UNUSED(nif); Q_UNUSED(iController); }

	Scene * scene;
	
	QPersistentModelIndex iBlock;

	QList<Controller*> controllers;
	
	QString name;

	friend class ControllerManager;
};

#endif
