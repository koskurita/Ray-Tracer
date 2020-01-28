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
    
    for(unsigned int i = 0; i < world.lights.size(); ++i) {//Loop through lights
     lightRay.direction = world.lights.at(i)->position - intersection_point;//Calculate Direction
     double sqrdLight = lightRay.direction.magnitude_squared();
     lightRay.direction = lightRay.direction.normalized();//Normalize
     lightRay.endpoint = world.lights.at(i)->position;//Get the position
     if(world.enable_shadows) {//Check if shadows are on
         Ray intToLight;
         intToLight.endpoint = intersection_point;
         intToLight.direction = lightRay.direction;
         intToLight.direction = intToLight.direction.normalized();
         Hit passToShadow = world.Closest_Intersection(intToLight);
         if(passToShadow.object != __null){//If there's something in the ray
             if(passToShadow.dist < sqrt(sqrdLight)) {//If the object is closer than int_point
                 
                 continue; //skip adding diffuse and specular
             }
         }
     }
     //Calculate Diffuse and Add to color
     lightColor = world.lights.at(i)->Emitted_Light(lightRay.direction);
     lightColor /= sqrdLight;
     double temp = std::max(dot(lightRay.direction, normal) , 0.0);
     color = (lightColor * color_diffuse * temp);
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
