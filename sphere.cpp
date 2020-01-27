#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
    Hit null = {__null, 0, 0};
    
    vec3 L = ray.endpoint - center;
    double b = dot(2*ray.direction, L);
    double c = dot(L, L) - radius*radius;
    
    double discriminant = b*b - 4*c;
    
    if(discriminant < 0){
        return null;
    }
    double t1 = (-b - sqrt(discriminant))/2;
    double t2 = (-b + sqrt(discriminant))/2;
    
    if(t1 < 0){
    //            std::cout << "hello";
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
