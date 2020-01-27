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
    
    vec3 v = ray.endpoint - center;
    double delta = pow(dot(ray.direction,v),2) - (dot(ray.direction,ray.direction))*(dot(v,v)-pow(radius,2));
    
    if ( delta > 0){
        std::cout << delta;
        double t1 = -(dot(ray.direction,v)) + sqrt(delta);
        double t2 = -(dot(ray.direction,v)) - sqrt(delta);
        double temp;
        if(t1 > t2){
            temp = t2;
        }
        else{
            temp = t1;
        }
        if(temp >= 0){
            return {this, temp, this->number_parts};
        }
        }
    std::cout << "hello";
    return {nullptr, 0, this->number_parts};
    
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
    normal = ((point - center)/radius).normalized();
    return normal;
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
    TODO; // calculate bounding box
    return box;
}
