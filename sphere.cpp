#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
    Hit hit = {__null, 0, 0};
    
    double b = dot(ray.direction, (ray.endpoint - center));
    double c = dot((ray.endpoint - center), (ray.endpoint - center)) - radius*radius;
    
    if(b*b-c < 0){
        return hit;
    }
    double t1 = b - sqrt(b*b)-c;
    double t2 = b + sqrt(b*b)-c;
    
    if(t1 < 0){
        return {this, t2, 0};
    }
    else if(t2 < 0){
        return {this, t1, 0};
    }
    else if(t1 < t2){
        return {this, t1, 0};
    }
    else if(t2 > t1){
        return {this, t2, 0};
    }
    else{
        return {__null, 0, 0};
    }

    
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
