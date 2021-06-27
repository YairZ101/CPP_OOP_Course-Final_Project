#include "pch.h"
#include "MyPolygon.h"

#define INF 10000

IMPLEMENT_SERIAL(MyPolygon, MyShape, 1)

MyPolygon::MyPolygon()
{
}

MyPolygon::~MyPolygon()
{
	delete this->points;
}

MyPolygon::MyPolygon(CPoint begin, CPoint end, int numEdges) : MyShape(begin, end)
{
	this->numEdges = numEdges;
	this->points = new CPoint[numEdges];
}

int MyPolygon::GetNumEdges() const
{
	return this->numEdges;
}

void MyPolygon::SetNumEdge(const int numEdges)
{
	this->numEdges = numEdges;
}

CPoint* MyPolygon::GetPoints() const
{
	return points;
}

void MyPolygon::SetPoints(const CPoint *points)
{
	memcpy(this->points, points, sizeof(CPoint) * this->GetNumEdges());
}

void MyPolygon::Draw(CPaintDC& dc) const
{
	dc.Polygon(this->points, this->numEdges);
}


// Given three colinear points p, q, r, the function checks if 
// point q lies on line segment 'pr' 
bool onSegment(CPoint p, CPoint q, CPoint r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(CPoint p, CPoint q, CPoint r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
        (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear 
    return (val > 0) ? 1 : 2; // clock or counterclock wise 
}

// The function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool doIntersect(CPoint p1, CPoint q1, CPoint p2, CPoint q2)
{
    // Find the four orientations needed for general and 
    // special cases 
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case 
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases 
}

// Returns true if the point p lies inside the polygon[] with n vertices 
bool MyPolygon::IsInShape(CPoint &p) const
{
    CPoint *polygon = this->GetPoints();
    int n = this->GetNumEdges();
    // There must be at least 3 vertices in polygon[] 
    if (n < 3)  return false;

    // Create a point for line segment from p to infinite 
    CPoint extreme = { INF, p.y };

    // Count intersections of the above line with sides of polygon 
    int count = 0, i = 0;
    do
    {
        int next = (i + 1) % n;

        // Check if the line segment from 'p' to 'extreme' intersects 
        // with the line segment from 'polygon[i]' to 'polygon[next]' 
        if (doIntersect(polygon[i], polygon[next], p, extreme))
        {
            // If the point 'p' is colinear with line segment 'i-next', 
            // then check if it lies on segment. If it lies, return true, 
            // otherwise false 
            if (orientation(polygon[i], p, polygon[next]) == 0)
                return onSegment(polygon[i], p, polygon[next]);

            count++;
        }
        i = next;
    } while (i != 0);

    // Return true if count is odd, false otherwise 
    return count & 1;  // Same as (count%2 == 1) 
}

int MyPolygon::GetUpperY() const
{
    int min = this->GetPoints()[0].y;
    for (int i = 1; i < this->GetNumEdges(); i++) {
        if (this->GetPoints()[i].y < min)
            min = this->GetPoints()[i].y;
    }
    return min;
}

int MyPolygon::GetLeftX() const 
{
    int min = this->GetPoints()[0].x;
    for (int i = 1; i < this->GetNumEdges(); i++) {
        if (this->GetPoints()[i].x < min)
            min = this->GetPoints()[i].x;
    }
    return min;
}

void MyPolygon::Serialize(CArchive& ar)
{
    MyShape::Serialize(ar);
    if (ar.IsStoring())
    {
        ar << numEdges;
        for (int i = 0; i < numEdges; i++)
            ar << points[i];
    }
    else // Loading, not storing
    {
        ar >> numEdges;
        delete this->points;
        this->points = new CPoint[numEdges];
        for (int i = 0; i < numEdges; i++) {
            ar >> points[i];
        }
    }
}