/* Domain.h is part of Kiva (Written by Neal Kruis)
 * Copyright (C) 2012-2013 Big Ladder Software <info@bigladdersoftware.com>
 * All rights reserved.
 *
 * Kiva is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Kiva is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Kiva.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef Domain_HPP
#define Domain_HPP

#include "Input.h"
#include "Mesher.h"

#include <fstream>

#include <boost/multi_array.hpp>

class Domain
{
public:

		// mesh
		Mesher meshX;
		Mesher meshY;
		Mesher meshZ;
		std::size_t nX;
		std::size_t nY;
		std::size_t nZ;

		// inherent properties
		boost::multi_array<double, 3> density;
		boost::multi_array<double, 3> specificHeat;
		boost::multi_array<double, 3> conductivity;

		// derived properties
		boost::multi_array<double, 3> cxp_c;
		boost::multi_array<double, 3> cxm_c;
		boost::multi_array<double, 3> cxp;
		boost::multi_array<double, 3> cxm;
		boost::multi_array<double, 3> cyp;
		boost::multi_array<double, 3> cym;
		boost::multi_array<double, 3> czp;
		boost::multi_array<double, 3> czm;

		// organizational properties
		enum CellType
		{
			EXTERIOR_AIR,  // 0
			EXTERIOR_GRADE,  // 1
			EXTERIOR_WALL,  // 2
			INTERIOR_AIR,  // 3
			INTERIOR_SLAB,  // 4
			INTERIOR_WALL,  // 5
			INTERIOR_INSULATION_EDGE,  // 6
			WALL_TOP,  // 7
			SYMMETRY,  // 8
			FAR_FIELD,  // 9
			DEEP_GROUND,  // 10
			NORMAL,  // 11
			ZERO_THICKNESS
		};
		boost::multi_array<CellType, 3>  cellType;

		std::size_t slabK;
		std::size_t slabImin;
		std::size_t slabImax;
		
public:

		Domain();
		Domain(Foundation &foundation);
		void setDomain(Foundation &foundation);
		double getDXP(size_t i);
		double getDXM(size_t i);
		double getDYP(size_t j);
		double getDYM(size_t j);
		double getDZP(size_t k);
		double getDZM(size_t k);
		double getKXP(size_t i,size_t j,size_t k);
		double getKXM(size_t i,size_t j,size_t k);
		double getKYP(size_t i,size_t j,size_t k);
		double getKYM(size_t i,size_t j,size_t k);
		double getKZP(size_t i,size_t j,size_t k);
		double getKZM(size_t i,size_t j,size_t k);
		void printCellTypes();

};


#endif
