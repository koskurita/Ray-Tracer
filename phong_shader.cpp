#include "light.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"
#include "object.h"

vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& normal,int recursion_depth) const
{
    vec3 color;
    Ray light_ray;
    vec3 light_color;
    
    for(unsigned int i = 0; i < world.lights.size(); ++i) {
        light_ray.direction = world.lights.at(i)->position - intersection_point;
        double mag_squared = light_ray.direction.magnitude_squared();
        light_ray.direction = light_ray.direction.normalized();
        light_ray.endpoint = world.lights.at(i)->position;
        
        light_color = world.lights[i]->Emitted_Light(light_ray.direction);
        light_color = light_color/mag_squared;
        
        Ray test;
        test.endpoint = intersection_point;
        test.direction = light_ray.direction;
        Hit anything_hit = world.Closest_Intersection(test);
        vec3 gg = world.lights.at(i)->position - intersection_point;
        if (anything_hit.dist < gg.magnitude()){
            double temp = std::max(dot(light_ray.direction, normal) , 0.0);
            color = (light_color * color_diffuse * temp);
            
            vec3 reflect_dir = (2 * dot(light_ray.direction, normal) * normal) - light_ray.direction;
            vec3 opposite_normal = ray.direction * -1;
            double specular = std::max(dot(reflect_dir, opposite_normal), 0.0);
            specular = pow(specular, specular_power);
            color += (light_color * color_specular * specular);
        }
        
        
    }
    
    color += color_ambient * (world.ambient_color * world.ambient_intensity);
    
    return color;
}
