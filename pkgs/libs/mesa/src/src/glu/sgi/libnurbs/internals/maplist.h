/*
 * SGI FREE SOFTWARE LICENSE B (Version 2.0, Sept. 18, 2008)
 * Copyright (C) 1991-2000 Silicon Graphics, Inc. All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice including the dates of first publication and
 * either this permission notice or a reference to
 * http://oss.sgi.com/projects/FreeB/
 * shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * SILICON GRAPHICS, INC. BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Except as contained in this notice, the name of Silicon Graphics, Inc.
 * shall not be used in advertising or otherwise to promote the sale, use or
 * other dealings in this Software without prior written authorization from
 * Silicon Graphics, Inc.
 */

/*
 * maplist.h
 *
 * $Date: 2012/03/29 17:22:18 $ $Revision: 1.1.1.1 $
 * $Header: /cvs/bao-parsec/pkgs/libs/mesa/src/src/glu/sgi/libnurbs/internals/maplist.h,v 1.1.1.1 2012/03/29 17:22:18 uid42307 Exp $
 */

#ifndef __glumaplist_h_
#define __glumaplist_h_

#include "types.h"
#include "defines.h"
#include "bufpool.h"

class Backend;
class Mapdesc;

class Maplist {
public:
			Maplist( Backend & );
    void 		define( long, int, int );
    inline void 	undefine( long );
    inline int		isMap( long );

    void 		initialize( void );
    Mapdesc * 		find( long );
    Mapdesc * 		locate( long );

private:
    Pool		mapdescPool;
    Mapdesc *		maps;
    Mapdesc **		lastmap;
    Backend &		backend;

    void 		add( long, int, int );
    void 		remove( Mapdesc * );
    void		freeMaps( void );
};

inline int
Maplist::isMap( long type )
{
    return (locate( type ) ? 1 : 0);
}

inline void 
Maplist::undefine( long type )
{
    Mapdesc *m = locate( type );
    assert( m != 0 );
    remove( m );
}
#endif /* __glumaplist_h_ */
