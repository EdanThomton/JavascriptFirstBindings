import { readdir, rm, mkdir } from "node:fs/promises";
import { gcc_compile_for_roborio } from "./build_utils/compiler.js"

const startTime = new Date();

const current_directory = decodeURI(import.meta.url).slice(7,-8);

const sources = await readdir(`${current_directory}sources/`, { recursive: true });

let c_sources = [];
for(let source of sources) {
    // test for files ending in '.cpp'
    if(/[\S]*.cpp$/.test(source)) {
        // emit '.cpp' file ending
        c_sources.push([source, source.slice(0,-4).replace(/[\s\S]*\//g,"")]);
    }
}

// clear build directory
try {

    await rm(`${current_directory}build`, { recursive: true });
    await mkdir(`${current_directory}build`);
    await mkdir(`${current_directory}build/objects`);

} catch {}

let success = true;

for(let c_source of c_sources) {
    let comp_res = await gcc_compile_for_roborio(
        `${current_directory}sources`,
        c_source[0],
        `${current_directory}build`,
        c_source[1]
    );

    if(comp_res == -1) {
        success = false;
    }
}

const totalTimeMS = (new Date()) - startTime;

if(success) {

    console.log(`\n\x1b[1m[\x1b[36mJSF-Build-Tool\x1b[39m] \x1b[92mBUILD SUCCESS \x1b[90m(${totalTimeMS}ms)\x1b[0m\n`);

} else {

    console.log(`\n\x1b[1m[\x1b[36mJSF-Build-Tool\x1b[39m] \x1b[91mBUILD FAILED \x1b[90m(${totalTimeMS}ms)\x1b[0m\n`);

}