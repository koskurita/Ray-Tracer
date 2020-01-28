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
    Ray lightRay;
    vec3 lightColor;
    
    for(unsigned int i = 0; i < world.lights.size(); ++i) {
     lightRay.direction = intersection_point - world.lights.at(i)->position;
     //double sqrdLight = lightRay.direction.magnitude_squared();
     lightRay.direction = lightRay.direction.normalized();
     lightRay.endpoint = world.lights.at(i)->position;
     if(world.enable_shadows == true) {
         Ray interception;
         interception.endpoint = intersection_point;
         interception.direction = -lightRay.direction;
         Hit test = world.Closest_Intersection(interception);
         // test if anything in the way
         if(test.object == __null){
             lightColor = world.lights[i]->Emitted_Light(lightRay.direction);
             lightColor = lightColor.normalized();
             double temp = std::max(dot(lightRay.direction, normal) , 0.0);
             color = (lightColor * color_diffuse * temp);

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
