/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:08:33 by abelov            #+#    #+#             */
/*   Updated: 2025/02/26 00:08:34 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float distance(const Point &p1, const Point &p2)
{
	float pt1_x = p1.getXFloat();
	float pt1_y = p1.getYFloat();
	float pt2_x = p2.getXFloat();
	float pt2_y = p2.getYFloat();

	double dist = sqrt(pow(pt2_x - pt1_x, 2)
		+ pow(pt2_y - pt1_y, 2));
	return (static_cast<float>(dist));
}

Point vector(const Point &pt1, const Point &pt2)
{
	float x1 = pt1.getXFloat();
	float x2 = pt2.getXFloat();

	float y1 = pt2.getYFloat();
	float y2 = pt1.getYFloat();

	float diffX = x2 - x1;
	float diffY = y1 - y2;

	return (Point(diffX, diffY));
}

float dotProduct(const Point &v1, const Point &v2)
{
	float x1 = v1.getXFloat();
	float x2 = v2.getXFloat();

	float y1 = v2.getYFloat();
	float y2 = v1.getYFloat();

	return (x1 * x2 + y2 * y1);
}

float angle(const Point &p, const Point &a, const Point &b)
{
	Point v1 = vector(p, a);
	Point v2 = vector(p, b);

	float dist1 = distance(p, a);
	float dist2 = distance(p, b);

	float divisor = dist1 * dist2;

	float angle = 0;
	if (divisor != 0)
		angle = std::acos(dotProduct(v1, v2) / (divisor));
	return (angle);
}

/**
 * https://clang.llvm.org/extra/clang-tidy/checks/performance/unnecessary-value-param.html
 * @param a
 * @param b
 * @param c
 * @param point
 * @return
 *
 * Algorithm: angle summation method:
 * 	If a point is inside a triangle, the sum of the angles formed between
 * 	the point and the three vertices of the triangle should be exactly 360° (or 2π radians).
 *
 * 	If the point is outside the triangle,
 * 	the sum of these angles will be less than 2π.
 *
 * 	If the point is on the boundary,
 * 	the sum might still be 2π, we also explicitly check for points
 * 	lying on vertices to return false.
 */
bool bspAngleMethod(Point const &a, Point const &b, Point const &c, Point const &point)
{
	float angle1 = angle(point, a, b);
	float angle2 = angle(point, b, c);
	float angle3 = angle(point, c, a);

	float sum = angle1 + angle2 + angle3;
	return (Fixed(sum) == Fixed((float) (2 * M_PI)));
}

float sign(const Point& p1, const Point& p2, const Point& p3)
{
	float pt1_x = p1.getXFloat();
	float pt1_y = p1.getYFloat();

	float pt3_x = p3.getXFloat();
	float pt3_y = p3.getYFloat();

	float pt2_y = p2.getYFloat();
	float pt2_x = p2.getXFloat();

	return (pt1_x - pt3_x) * (pt2_y - pt3_y) -
		   (pt2_x - pt3_x) * (pt1_y - pt3_y);
}

/**
 * Efficient approach, which avoids costly trigonometric functions.
 *
 * @param a
 * @param b
 * @param c
 * @param point
 * @return
 */
bool bspCrossProductMethod(Point const &a, Point const &b, Point const &c, Point const &point)
{
	float d1 = sign(point, a, b);
	float d2 = sign(point, b, c);
	float d3 = sign(point, c, a);

	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos); // True if all are positive or all are negative
}

Fixed	getArea(const Point &a, const Point &b, const Point &c)
{
	Fixed surf1 = a.getX() * (b.getY() - c.getY());
	Fixed surf2 = b.getX() * (c.getY() - a.getY());
	Fixed surf3 = c.getX() * (a.getY() - b.getY());

	Fixed total = (surf1 + surf2 + surf3).abs() / Fixed(2);

	return (total);
}

bool bspAreaMethod(Point const &a, Point const &b, Point const &c, Point const &point)
{
	Fixed total = getArea(a, b, c).abs();
	Fixed PBC = getArea(point, b, c).abs();
	Fixed PAC = getArea(point, a, c).abs();
	Fixed PAB = getArea(point, a, b).abs();

	// The comparison using == is problematic because
	// floating-point calculations (or fixed-point arithmetic)
	// may introduce tiny rounding errors.
	return (total - (PBC + PAC + PAB)).abs() < Fixed(Fixed::getEpsilon()); // Approximately equal in Q24.8
	return (total == (PBC + PAC + PAB));
}

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point)
{
	// "This is not a triangle !"
	if (a.isEqual(b) || a.isEqual(c) || b.isEqual(c))
		return (false);

	// "The point coincides with one of the edges !"
	if (point.isEqual(a) || point.isEqual(b) || point.isEqual(c))
		return (false);

	return (bspCrossProductMethod(a, b, c, point)); // faster and more numerically stable
	return (bspAreaMethod(a, b, c, point));
	return (bspAngleMethod(a, b, c, point));
}
