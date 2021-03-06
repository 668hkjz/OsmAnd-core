/**
* @file
*
* @section LICENSE
*
* OsmAnd - Android navigation software based on OSM maps.
* Copyright (C) 2010-2013  OsmAnd Authors listed in AUTHORS file
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __MODEL_AMENITY_CATEGORY_H_
#define __MODEL_AMENITY_CATEGORY_H_

#include <cstdint>

#include <QString>
#include <QStringList>

#include <OsmAndCore.h>
#include <OsmAndCore/CommonTypes.h>

namespace OsmAnd {

    class ObfPoiSectionReader_P;

    namespace Model {

        class OSMAND_CORE_API AmenityCategory
        {
        private:
        protected:
            AmenityCategory();

            QString _name;
            QStringList _subcategories;
        public:
            virtual ~AmenityCategory();

            const QString& name;
            const QStringList& subcategories;

        friend class OsmAnd::ObfPoiSectionReader_P;
        };

    } // namespace Model

} // namespace OsmAnd

#endif // __MODEL_AMENITY_CATEGORY_H_
