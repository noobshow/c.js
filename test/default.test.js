import test from 'ava';
import runner from './runner';

test.cb('Empty Block', runner(function () {
    {}
}));

test.cb('Zero Argument Function Definition Empty Block', runner(function () {
    function buhler () {
    }
}));

test.cb('Zero Argument Function Definition Block Statement List', runner(function () {
    function buhler () {
        var michael;
        var other;
    }
}));

test.cb('Empty Statement', runner(function () {
    ;
}));

test.cb('Variable Declaration', runner(function () {
    var buhler;
}));

test.cb('Variable Declaration List', runner(function () {
    var buhler, michael;
}));

test.cb('Single Line Comment', runner(function () {
    // this is a comment
}));

test.cb('Multi Line Comment', runner(function () {
    var buhler;
    /* this is a
     * multiline comment
     */
    var michael;
}));
