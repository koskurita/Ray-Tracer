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
    
    for(unsigned int i = 0; i < world.lights.size(); i++){
        light_ray.direction = intersection_point - world.lights[i].position;
        light_ray.direction = light_ray.normalized();
        light_ray.endpoint = world.lights[i]->position;
        
        vec3 l = intersection_point - world.lights[i].position;
        vec3 intensity = world.lights[i].Emitted_Light(light_ray);
        
        color = (intensity * color_diffuse * world.lights[i].brightness  * std::max(0, dot(normal.normalized(), l.0)));
    }
    
    return color;
}
