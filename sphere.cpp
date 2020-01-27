#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
    Hit null = {__null, 0, 0};
    
    vec3 L = ray.endpoint - center;
    double b = dot(ray.direction*2, L);
    double c = dot(L, L) - radius*radius;
    
    double discriminant = (b*b) - (4*c);
    
    if(discriminant < 0){
        std::cout << " test 1";
        return null;
    }
    
    double t1 = (-b - sqrt(discriminant))/2;
    double t2 = (-b + sqrt(discriminant))/2;
    
    if(t1 < 0){
        std::cout << " test 2";
    //            std::cout << "hello";
        Hit hit = {this, t2, 0};
        return hit;
    }
    else if(t2 < 0){
        std::cout << " test 3";
      Hit hit = {this, t1, 0};
        return hit;
    }
    else if(t1 < t2){
        std::cout << " test 4";
    //            std::cout << "hello";
        Hit hit = {this, t1, 0};
        return hit;
    }
    else if(t2 > t1){
        std::cout << " test 5";
    //            std::cout << "hello";
        Hit hit = {this, t2, 0};
        return hit;
    }
    else{
        std::cout << " test 6";
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
