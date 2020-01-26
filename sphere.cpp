#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
    vec3 endpt_to_center = center - ray.endpoint;
    double time = dot(endpt_to_center, ray.direction);
    vec3 t = Point(time);
    vec3 vec_t = center - t;
    double distance_x = sqrt(pow(radius, 2) - vec_t.magnitude_squared());
    double intersection_time = time - distance_x;
    
    Hit hit;
    hit.object = new Sphere;
    hit.object = *this;
    hit.dist = intersection_time;

    return hit;
    
    /*
    vec3 t1p = ro + rd * t1;
    vec3 sphereToOrigin = normalize(ro - s);
    vec3 normal = normalize(t1p - s);
    col = vec3(dot(normal, sphereToOrigin));
    */
    
    
    
   // return {0,0,0};
}

vec3 Sphere::Normal(const vec3& point, int part) const
{
    vec3 normal;
    TODO; // compute the normal direction
    return normal;
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
    TODO; // calculate bounding box
    return box;
}
