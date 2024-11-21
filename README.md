# WebAssembly
A test task for acquainted with the Emscripten SDK, WebAssembly(wasm), SDL2, SDL_ttf, etc.

## 🚀 Functional

- 📌 Using the SDL2 library to graphically draw text on canvas
- 📌 Using the SDL_ttf to create a custom font for text
- 📌 Using two parameters ('o' and 't') in the url path for display text from url and his display orientation (parameter 'o' takes 2 values, either h (horizontal) or v (vertical))

## 🛠️ Technology

The project was created using:
- [C++](https://en.cppreference.com/w/) — A detailed guide to the C++ programming language and its standard library
- [JavaScript](https://developer.mozilla.org/en-US/docs/Web/JavaScript) — Comprehensive reference and tutorials for JavaScript
- [HTML](https://developer.mozilla.org/en-US/docs/Web/HTML) — A complete guide to HTML elements, attributes, and best practices
- [Emscripten](https://emscripten.org/docs/) — Documentation for IDE
- [SDL2](https://github.com/emscripten-ports/SDL2) — I use this version for Emscripten
- [WebAssembly](https://developer.mozilla.org/en-US/docs/WebAssembly) - WebAssembly (MDN)

## 📖 Installation and use

### 1. Cloning a repository
```bash
git clone https://github.com/Dmitry3755/WebAssembly.git
```
### 2. Installing dependencies (If necessary)
- Installation emsdk (see the link Emscripten)
- If, after installing emsdk, the SDL library doesn`t support the SDL_RenderCopyEx() method. You need to download SDL2 (see the link SDL2)
- You may have to download Cmake

## 🧪 Usage examples

- Open VS Code and open console. Print command into console: 'python -m http.server'. This command start http server
- Compile the project
- Open your browser and then open your page with project (example: http://localhost:your_port/draw.html)
- Add in your url path 2 parameters 'o' (orientation) and 't' (test) (example: http://localhost:your_port/draw.html?o=v&t=Hello)
  
![image](https://github.com/user-attachments/assets/0e85ada6-2467-413c-a961-f59a1a6dd569)
![image](https://github.com/user-attachments/assets/5c319c37-3d23-4f9a-9a16-2d6785d4d609)



  
