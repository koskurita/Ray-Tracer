#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
    Hit null;
    
    double b = dot(ray.direction, (ray.endpoint - center));
    double c = dot((ray.endpoint - center), (ray.endpoint - center)) - radius*radius;
    
    if(b*b-c < 0){
        return null;
    }
    double t1 = -b - sqrt(b*b)-c;
    double t2 = -b + sqrt(b*b)-c;
    
    if(t1 < 0){
                std::cout << "hello";
        return {this, t2, 0};
    }
    else if(t2 < 0){
    //            std::cout << "hello";
        return {this, t1, 0};
    }
    else if(t1 < t2){
    //            std::cout << "hello";
        return {this, t1, 0};
    }
    else if(t2 > t1){
    //            std::cout << "hello";
        return {this, t2, 0};
    }
    else{
        return null;
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
