/*
Title: AABB-3D
File Name: VertexShader.glsl
Copyright � 2015
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

#version 400 core // Identifies the version of the shader, this line must be on a separate line from the rest of the shader code
 
layout(location = 0) in vec3 in_position;	// Get in a vec3 for position
layout(location = 1) in vec4 in_color;		// Get in a vec4 for color

out vec4 color; // Our vec4 color variable containing r, g, b, a

uniform mat4 MVP; // Our uniform MVP matrix to modify our position values

void main(void)
{
	color = in_color;	// Pass the color through
	gl_Position = MVP * vec4(in_position, 1.0); //w is 1.0, also notice cast to a vec4
}