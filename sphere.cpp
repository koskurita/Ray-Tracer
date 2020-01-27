#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
    Hit hit = {nullptr, 0, 0};
    
    vec3 p = center - ray.endpoint;
    double t = dot(ray.direction, t);
    vec3 tca = ray.Point(p);
    
    double d = sqrt(dot(p, p) - dot(tca, tca));
    
    if(d > radius){
        return {nullptr, 0, 0};
    }
    
    double thc = sqrt(radius*radius - d*d);
    
    double t1 = t - thc;
    double t2 = t + thc;
    
    if(t1 < t2){
        return {this, t1, 0};
    }
    else{
        return {this, t2, 0};
    }
    return hit;
    
    /*
    double time = dot(endpt_to_center, ray.direction);
    vec3 t = ray.Point(time);
    vec3 vec_t = center - t;
    double distance_x = sqrt(pow(radius, 2) - vec_t.magnitude_squared());
    double intersection_time = time - distance_x;
    
    Hit hit;
    hit.object = this;
    hit.dist = intersection_time;
    hit.part = 0;

    return hit;
     */
    
}

vec3 Sphere::Normal(const vec3& point, int part) const
{
    vec3 normal;
    normal = ((point - center)/radius).normalized();
    return normal;
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
    TODO; // calculate bounding box
    return box;
}
