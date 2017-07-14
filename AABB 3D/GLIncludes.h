/*
Title: AABB-3D
File Name: GLIncludes.h
Copyright © 2015
Original authors: Brockton Roth
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Description:
This is an Axis-Aligned Bounding Box collision test. This is in 3D.
Contains two cubes, one that is stationary and one that is moving. They are bounded
by AABBs (Axis-Aligned Bounding Boxes) and when these AABBs collide, the moving
object "bounces" on the X-axis (because that is the only direction the object is
moving). The algorithm will detect collision along any axis, but will not be able
to output the axis of collision because it doesn't know. Thus, we assume X and
hardcode in the X-axis bounce. If you would like to know the axis of collision,
try out the Swept AABB collision.
There is a physics timestep such that every update runs at the same delta time,
regardless of how fast or slow the computer is running. The cubes will not be the
exact same as their AABBs, since they are rotating while the AABBs are aligned on
the X-Y-Z axes but should you wish to see the AABBs match the cubes perfectly,
simply comment out the rotate lines (obj1->Rotate, obj2->Rotate).
*/

#ifndef _GL_INCLUDES_H
#define _GL_INCLUDES_H

#include "gl\glew.h"
#include "glfw\glfw3.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"
#include "glm\gtc\quaternion.hpp"
#include "glm\gtx\quaternion.hpp"

// We create a VertexFormat struct, which defines how the data passed into the shader code wil be formatted
struct VertexFormat
{
	glm::vec4 color;	// A vector4 for color has 4 floats: red, green, blue, and alpha
	glm::vec3 position;	// A vector3 for position has 3 float: x, y, and z coordinates

	// Default constructor
	VertexFormat()
	{
		color = glm::vec4(0.0f);
		position = glm::vec3(0.0f);
	}

	// Constructor
	VertexFormat(const glm::vec3 &pos, const glm::vec4 &iColor)
	{
		position = pos;
		color = iColor;
	}
};

#endif _GL_INCLUDES_H