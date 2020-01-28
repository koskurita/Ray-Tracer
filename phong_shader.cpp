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
    
    for(unsigned int i = 0; i < world.lights.size(); ++i) {
     light_ray.direction = world.lights.at(i)->position - intersection_point;
     double sqrdLight = light_ray.direction.magnitude_squared();
     light_ray.direction = light_ray.direction.normalized();
     light_ray.endpoint = world.lights.at(i)->position;
     if(world.enable_shadows) {
         Ray intToLight;
         intToLight.endpoint = intersection_point;
         intToLight.direction = light_ray.direction;
         intToLight.direction = intToLight.direction.normalized();
         Hit passToShadow = world.Closest_Intersection(intToLight);
         if(passToShadow.object != __null){
             if(passToShadow.dist < sqrt(sqrdLight)) {
                 vec3 lightColor;
                 lightColor = world.lights.at(i)->Emitted_Light(light_ray.direction);
                 lightColor /= sqrdLight;
                 double temp = std::max(dot(light_ray.direction, normal) , 0.0);
                 color = (lightColor * color_diffuse * temp);
             }
         }
     }
    }
    
    
    /*
    for(unsigned int i = 0; i < world.lights.size(); i++){
        light_ray.direction = intersection_point - world.lights[i]->position;
        light_ray.direction = light_ray.direction.normalized();
        light_ray.endpoint = world.lights[i]->position;
        
        vec3 intensity = world.lights[i]->Emitted_Light(light_ray.direction);
        
        double gg = std::max(0.0, dot(normal.normalized(), light_ray.direction));
        
        color = gg * color_diffuse * intensity;
    }
     */
    
    return color;
}
