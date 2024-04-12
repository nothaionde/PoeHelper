#include "TextureUtils.h"

#define STB_IMAGE_IMPLEMENTATION
#include "vendor/stb_image/stb_image.h"

namespace PoeHelper {
	// Simple helper function to load an image into a OpenGL texture with common settings
	bool TextureUtils::LoadTextureFromFile(const char* filename)
	{
		// Load image information from file
		int image_width, image_height, image_channels;
		stbi_info(filename, &image_width, &image_height, &image_channels);

		// Load image data from file
		unsigned char* image_data = stbi_load(filename, &image_width, &image_height, &image_channels, STBI_rgb_alpha);
		if (image_data == nullptr)
		{
			// TODO: Throw an error or handle the failure
			return 0;
		}

		// Create a OpenGL texture identifier
		GLuint image_texture;
		glGenTextures(1, &image_texture);
		glBindTexture(GL_TEXTURE_2D, image_texture);

		// Setup filtering parameters for display
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same

		// Upload pixels into texture
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
		stbi_image_free(image_data);

		return image_texture;
	}
	unsigned char* TextureUtils::GetPixelsFromFile(const char* filename)
	{
		int image_width, image_height, image_channels;
		stbi_info(filename, &image_width, &image_height, &image_channels);

		// Load image data from file
		return stbi_load(filename, &image_width, &image_height, &image_channels, STBI_rgb_alpha);
	}
}
