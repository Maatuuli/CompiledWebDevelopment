
/*
service mysql start
service mysql status
service mysql stop




use cgi_database;

CREATE TABLE products (
    id VARCHAR(256) PRIMARY KEY,
    product_id VARCHAR(256) NOT NULL,
    title VARCHAR(256) NOT NULL,
    description TEXT NOT NULL
);

DROP TABLE products;

SHOW FIELDS FROM products;

SELECT * FROM products;

INSERT INTO products (id, product_id, title, description)
VALUES ('fq372g592dd2', 'INC-70', 'wooden chair (red, ä)', 'This is a chair description (ÜÖÄäöüµß@). Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi.'),
('jfpf349fuitg', 'INC-319', 'bed (queen-size, oak, ö)', 'This is a long description for the product bed (ÜÖÄäöüµß@). Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis.'),
('ldn237djnr5d', 'INC-201', 'wooden table (1.2x2.2m, ü)', 'This is a long description for the wooden table (ÜÖÄäöüµß@). Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat.'),
('pkzdt483hdf3', 'INC-7', 'tv stand (oak, µ)', 'Every tv stand needs a long description (ÜÖÄäöüµß@). Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat.'),
('trgj472g14jk', 'INC-191', 'cupboard (oak, Ä)', 'This cupboard has a long description (ÜÖÄäöüµß@). Nam liber tempor cum soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum.'),
('dfgwir39jw72', 'INC-518', 'steel table (Ü)', 'This table was made of steel (ÜÖÄäöüµß@). Ut wisi enim ad nam liber tempor cum soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum.'),
('gtpe83nsmgor', 'INC-391', 'ceramic tiles (white, Ö)', 'These white tiles are made of ceramic and have no coloured patterns (ÜÖÄäöüµß@). Ut wisi enim ad nam liber tempor cum soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum.'),
('8ej32bf7dkt4', 'INC-399', 'ceramic tiles (with pattern, Ä)', 'These wonderful tiles are made of ceramic and have coloured patterns (ÜÖÄäöüµß@). Ut wisi enim ad nam liber tempor cum soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum.'),
('d92bnf7sh4gs', 'INC-71', 'wooden chair (black, ÜÖÄ)', 'This black chair is the 2nd variant of the red chair (ÜÖÄäöüµß@). Soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum.'),
('dvike38sdsf4', 'INC-72', 'wooden chair (brown, öäü)', 'This brown chair is the 3rd variant of the red chair (ÜÖÄäöüµß@). Quod mazim placerat facer possim assum.');

 */


struct type_product {
    char* id;
    char* product_id;
    char* title;
    char* description;
};

struct type_product products[] = {
    {.id="jfpf349fuitg", .product_id="INC-319", .title="bed (queen-size, oak, ö)",        .description="This is a long description for the product bed (ÜÖÄäöüµß@). Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis."},
    {.id="gtpe83nsmgor", .product_id="INC-391", .title="ceramic tiles (white, Ö)",        .description="These white tiles are made of ceramic and have no coloured patterns (ÜÖÄäöüµß@). Ut wisi enim ad nam liber tempor cum soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum."},
    {.id="8ej32bf7dkt4", .product_id="INC-399", .title="ceramic tiles (with pattern, Ä)", .description="These wonderful tiles are made of ceramic and have coloured patterns (ÜÖÄäöüµß@). Ut wisi enim ad nam liber tempor cum soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum."},
    {.id="trgj472g14jk", .product_id="INC-191", .title="cupboard (oak, Ä)",               .description="This cupboard has a long description (ÜÖÄäöüµß@). Nam liber tempor cum soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum."},
    {.id="dfgwir39jw72", .product_id="INC-518", .title="steel table (Ü)",                 .description="This table was made of steel (ÜÖÄäöüµß@). Ut wisi enim ad nam liber tempor cum soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum."},
    {.id="pkzdt483hdf3", .product_id="INC-7",   .title="tv stand (oak, µ)",               .description="Every tv stand needs a long description (ÜÖÄäöüµß@). Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat."},
    {.id="d92bnf7sh4gs", .product_id="INC-71",  .title="wooden chair (black, ÜÖÄ)",       .description="This black chair is the 2nd variant of the red chair (ÜÖÄäöüµß@). Soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum."},
    {.id="dvike38sdsf4", .product_id="INC-72",  .title="wooden chair (brown, öäü)",       .description="This brown chair is the 3rd variant of the red chair (ÜÖÄäöüµß@). Quod mazim placerat facer possim assum."},
    {.id="fq372g592dd2", .product_id="INC-70",  .title="wooden chair (red, ä)",           .description="This is a chair description (ÜÖÄäöüµß@). Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi."},
    {.id="ldn237djnr5d", .product_id="INC-201", .title="wooden table (1.2x2.2m, ü)",      .description="This is a long description for the wooden table (ÜÖÄäöüµß@). Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat."},
};


struct type_quote {
    char* id;
    char* author;
    char* quote;
};


struct type_quote quotes[] = {
    {.id="iw9354bf61jd", .author="Bertholdt Brecht",            .quote="...it is simplicity that is difficult to make."},
    {.id="83nfjkef612f", .author="Chuck B. Falconer",           .quote="It is possible to generate accurate code with C. It is also possible with assembly language. However, doing so requires good programmers with plenty of experience. You can get equal quality from poorer programmers with less experience by using Ada. I leave it to you what you will get with experienced good programmers and Ada."},
    {.id="w395mg62fd4g", .author="Martin Golding",              .quote="Always code as if the guy who ends up maintaining your code will be a violent psychopath who knows where you live."},
    {.id="cdj834ndha42", .author="Edsger W. Dijkstra",          .quote="Program testing can be a very effective way to show the presence of bugs, but is hopelessly inadequate for showing their absence."},
    {.id="fk83hfe2hbf3", .author="Unknown",                     .quote="Don't include a single line in your code which you could not explain to your grandmother in a matter of two minutes. And of course... assume your grandmother is not Ada Lovelace."},
    {.id="pei49kf827h5", .author="Brian W. Kernighan",          .quote="Debugging is twice as hard as writing the code in the first place. Therefore, if you write the code as cleverly as possible, you are, by definition, not smart enough to debug it."},
    {.id="heo9823nm571", .author="Albert Einstein",             .quote="Insanity is doing the same thing over and over and expecting different results."},
    {.id="a04n5hf72f62", .author="Cory House",                  .quote="Code is like humor. When you have to explain it, it’s bad."},
    {.id="t3ef84nfgq5f", .author="Kent Beck",                   .quote="Make it work, make it right, make it fast."},
    {.id="ndfe6253bdu4", .author="Paulo Coelho",                .quote="The core of beauty is simplicity!"},
    {.id="4jd71bc93gfd", .author="Murphy's Introduction to C",  .quote="The C Programming Language — A language which combines the flexibility of assembly language with the power of assembly language."},
    {.id="mfue84ns62g6", .author="Edsger W. Dijkstra",          .quote="If debugging is the process of removing software bugs, then programming must be the process of putting them in."},
    {.id="giestgw734jg", .author="Bjarne Stroustrup",           .quote="In C++ it's harder to shoot yourself in the foot, but when you do, you blow off your whole leg."},
    {.id="eit84mngje63", .author="Bob Gray",                    .quote="Writing in C or C++ is like running a chain saw with all the safety guards removed."},
};


char*
getDatabaseServerName(void)
{
    return "subdomain.your-domain.com";
}


char*
getDatabaseUsername(void)
{
    return "your_username";
}


char*
getDatabasePassword(void)
{
    return "your_database_password";
}

char*
getDatabaseName(void)
{
    return "your_database_name";
}

