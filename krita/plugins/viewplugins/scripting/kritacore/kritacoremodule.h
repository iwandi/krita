/*
 *  Copyright (c) 2005 Cyrille Berger <cberger@cberger.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Library General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef KRITA_KROSS_KRITACOREMODULE_H
#define KRITA_KROSS_KRITACOREMODULE_H

#include <QString>
#include <QVariant>
#include <QObject>

#define KROSS_MAIN_EXPORT KDE_EXPORT

#if 0

#include <api/class.h>
#include <api/module.h>

namespace Kross { namespace Api {
    class Manager;
}}

#endif

class KisView;

namespace Kross { namespace KritaCore {

    /**
     * The main KritaCoreModule class enables access to the Krita
     * functionality from within the Kross scripting backends.
     */
    class KritaCoreModule : public QObject
    {
            Q_OBJECT
        public:
            KritaCoreModule(KisView* view);
            virtual ~KritaCoreModule();

        public slots:

            /**
            * Returns the \a KoApplicationAdaptor object.
            */
            QObject* application();

#if 0
            //TODO KisView::document() needs to be public to have this working!
            /**
            * Returns the \a KoDocumentAdaptor object.
            */
            QObject* document();
#endif

            /**
            * Returns the \a KritaCoreProgress object.
            */
            QObject* progress();

            /**
            * This function return the \a Image associated with the
            * currently loaded document.
            *
            * Example (in Ruby) :
            * @code
            * require 'Krita'
            * image = Krita.image()
            * @endcode
            */
            QObject* image();

#if 0
            /**
             * This function return a new Image.
             * It takes four arguments :
             *  - width
             *  - height
             *  - colorspace id
             *  - name of the image
             *
             * And in return you get an Image object.
             * 
             * For example (in ruby) :
             * @code
             * Krosskritacore::newImage(10,20, "RGBA", "kikoo")
             * @endcode
             */
            Kross::Api::Object::Ptr newImage(Kross::Api::List::Ptr);
#endif

            /**
             * This function return a new Color with the given RGB triplet
             * It takes three arguments :
             *  - red color (0 to 255)
             *  - blue color (0 to 255)
             *  - green color (0 to 255)
             * 
             * For example (in ruby) :
             * @code
             * require "Krita"
             * redcolor = Krita.createRGBColor(255,0,0)
             * whitecolor = Krita.createRGBColor(255,255,255)
             * @endcode
             */
            QObject* createRGBColor(int r, int g, int b);

            /**
             * This function return a new Color with the given HSV triplet
             * It takes three arguments :
             *  - hue color (0 to 255)
             *  - saturation color (0 to 255)
             *  - value color (0 to 255)
             * 
             * For example (in ruby) :
             * @code
             * require "Krita"
             * Krita.createHSVColor(255,125,0)
             * @endcode
             */
            QObject* createHSVColor(int hue, int saturation, int value);

            /**
             * This function return a \a Pattern taken from the list of ressources
             * of krita
             * It takes one argument :
             *  - the name of the pattern
             * 
             * For example (in ruby) :
             * @code
             * require "Krita"
             * brickspattern = Krita.pattern("Bricks")
             * @endcode
             */
            QObject* pattern(const QString& patternname);

            /**
             * This function return a \a Brush taken from the list of ressources
             * of krita
             * It takes one argument :
             *  - the name of the brush
             * 
             * For example (in ruby) :
             * @code
             * require "Krita"
             * circlebrush = Krita.brush("Circle (05)")
             * @endcode
             */
            QObject* brush(const QString& brushname);

            /**
             * This function return a Brush with a circular shape
             * It takes four arguments :
             *  - width
             *  - height
             *  - width of the shading
             *  - height of the shading
             * 
             * If the shading isn't specified, no shading will be used.
             * 
             * For example (in ruby) :
             * @code
             * require "Krita"
             * plaincircle = Krita.createCircleBrush(10,20,0,0)
             * gradientcircle = Krita.createCircleBrush(10,20,5,10)
             * @endcode
             */
            QObject* createCircleBrush(uint w, uint h, uint hf, uint vf);

            /**
             * This function return a Brush with a rectangular shape
             * It takes four arguments :
             *  - width
             *  - height
             *  - width of the shading
             *  - height of the shading
             * 
             * If the shading isn't specified, no shading will be used.
             * 
             * For example (in ruby) :
             * @code
             * require "Krita"
             * plainrectangle = Krita.createRectBrush(10,20,0,0)
             * gradientrectangle = Krita.createRectBrush(10,20,5,10)
             * @endcode
             */
            QObject* createRectBrush(uint w, uint h, uint hf, uint vf);

#if 0
            /**
             * This function return a Filter taken from the list of ressources
             * of krita
             * It takes one argument :
             *  - the name of the filter
             * 
             * For example (in ruby) :
             * @code
             * Krosskritacore::getFilter("invert")
             * @endcode
             */
            Kross::Api::Object::Ptr getFilter(Kross::Api::List::Ptr);
            /**
             * This function loads a Brush and then returns it.
             * It takes one argument: the filename of the brush.
             */
            Kross::Api::Object::Ptr loadBrush(Kross::Api::List::Ptr);
            /**
             * This function loads a Pattern and then returns it.
             * It takes one argument: the filename of the pattern.
             */
            Kross::Api::Object::Ptr loadPattern(Kross::Api::List::Ptr);
            /**
             * This function return the directory where the script is located.
             */
            Kross::Api::Object::Ptr getPackagePath(Kross::Api::List::Ptr);
        private:
            QString m_packagePath;
#endif

        private:
            class Private;
            Private* const d;
    };

}}

#endif
