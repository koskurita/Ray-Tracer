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
    std:: cout << ray;
    vec3 v = ray.endpoint - this->center;
    vec3 w = ray.direction;
    
    //std::cout << "Our sphere's center : " << this->center << '\n';
    //std::cout << "Our vectors : " << v << '|' << w << '\n';
    
    double D = pow(dot(w, v),2) - (v.magnitude_squared()-pow(radius,2));
    //if (D >= 0) std::cout << "Our determinant: " << D << '\n';
    //std::cout << "Our dot(w,v): " << dot(w,v) << '\n';
    if (D < 0){
        std::cout << "gg ";
         return {nullptr, 0, 0};
    }
    else if (D == 0) {
        double t = -dot(w,v);
        return {this, t, number_parts};
    }
    else if (D > 0) {
        double t0 = -dot(w,v)-sqrt(D);
        double t1 = -dot(w,v)+sqrt(D);
        if (t0 >= t1){
            double tmp = t0; t0 = t1; t1 = tmp;
        }
        if (t0 < 0){
            t0 = 0;
        }
        return {this, t0, number_parts};
    }
    return {nullptr, 0, 0};
    
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
