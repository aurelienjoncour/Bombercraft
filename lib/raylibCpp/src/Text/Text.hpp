/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Text
*/

#ifndef MODEL_HPP
#define MODEL_HPP

#include "../../include/include.hpp"

#include "IText.hpp"

namespace raylib
{
    class Text : public IText
    {
        public :
            Text(const std::string &text, MyVector2 position,
            size_t size, RColor color);
            ~Text();

            void draw();

            void setText(const std::string &text);
            void setPosition(MyVector2 position);
            void setFont(const std::string &path);
            void setColor(RColor color);
            void setFontSize(size_t size);
            void setLimit(MyVector4 limit);

            void removeFont();
            void removeLimit();

        private :
            std::string _text;
            MyVector2 _position;
            Font _font;
            RColor _color;
            size_t _size;
            Rectangle _limit;
            bool _hasFont;
    };
};

#endif // MODEL_HPP