//=============================================================================
//  MuseScore
//  Music Composition & Notation
//  $Id: tablature.h 5566 2012-04-22 08:26:29Z lvinken $
//
//  Copyright (C) 2002-2011 Werner Schweer
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2
//  as published by the Free Software Foundation and appearing in
//  the file LICENCE.GPL
//=============================================================================

#ifndef __TABLATURE_H__
#define __TABLATURE_H__

#include "xml.h"

class Chord;

//---------------------------------------------------------
//   Tablature
//---------------------------------------------------------

class Tablature {
      QList<int>  stringTable;
      int         _frets;

      static bool bFretting;

public:
      Tablature() {}
      Tablature(int numFrets, int numStrings, int strings[]);
      Tablature(int numFrets, QList<int>& strings);
      bool        convertPitch(int pitch, int* string, int* fret) const;
      int         fret(int pitch, int string) const;
      void        fretChord(Chord * chord) const;
      int         getPitch(int string, int fret) const;
      int         strings() const         { return stringTable.size(); }
      QList<int>  stringList() const      { return stringTable; }
      int         frets() const           { return _frets; }
      void        read(const QDomElement&);
      void        write(Xml&) const;
      void        readMusicXML(const QDomElement& de);
      void        writeMusicXML(Xml& xml) const;
      };

extern Tablature guitarTablature;
#endif

