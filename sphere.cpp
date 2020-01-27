#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
    /*
    vec3 endpt_to_center = ray.endpoint - center;
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
    
    Vec3f L = center - ray.endpoint;
    double tca = dot(L, dir);
    if(tca < 0){
        return {nullptr, 0, 0}
    }
    // if (tca < 0) return false;
    double d2 = dot(L, L) - tca * tca;
    if (d2 > radius*radius) return false;
    double thc = sqrt(radius*radius - d2);
    t0 = tca - thc;
    t1 = tca + thc;
    if(t0 < t1){
        return {this, t0, 0};
    }
    else{
        return {this, t1, 0};
    }
    return {0,0, 0}
    
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
