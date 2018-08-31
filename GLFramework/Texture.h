#pragma once

class Texture
{
public:

	struct TextureInfo
	{
		TextureInfo(
			GLuint idx,
			bool bAlpha,
			std::vector<GLubyte>&& v) : uTextureIdx{ idx }, hasAlpha{ bAlpha }, bytes{ v } {};

		GLubyte* getBytes() { return &(bytes[0]); }

		GLuint					uTextureIdx{ 0 };
		bool					hasAlpha{ false };
		std::vector<GLubyte>	bytes;
		int						height;
		int						width;
	};

private:

	static GLuint				m_uGlobalTexID;

	GLuint						m_uLocalTexID;
	std::vector<TextureInfo>	m_VtiTextures;
	GLboolean					m_bHasAlpha{ false };
	GLboolean					m_bImgLoaded{ false };

public:
	Texture();
	~Texture();

	size_t textureCount() const;
	void load(std::string path);

	void drawStart(bool usingEnv = true);
	void drawEnd();
};

