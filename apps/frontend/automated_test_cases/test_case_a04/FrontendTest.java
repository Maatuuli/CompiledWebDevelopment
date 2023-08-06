/*
 * Compile as a .jar package with this command:
 * ?> javac -d ./test_case_a04/classes --class-path "./selenium-server-4.10.0.jar" ./Helper.java ./test_case_a04/FrontendTest.java; cd ./test_case_a04/classes; jar --create --file=../../test_case_a04.jar  --manifest=../../manifest.mf ./*.class; cd -
 * 
 * Execute with:
 * ?> java -jar test_case_a04.jar
 * 
 * Show details from the JAR file with:
 * ?> jar tvf test_case_a04.jar
 *
 */

import org.openqa.selenium.By;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.chrome.ChromeOptions;
import org.openqa.selenium.Dimension;
import org.openqa.selenium.remote.DesiredCapabilities;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.logging.LogEntries;
import org.openqa.selenium.logging.LogEntry;
import org.openqa.selenium.logging.LogType;

import java.util.Date;
import java.io.IOException;
import java.nio.file.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;


public class FrontendTest
{
    public static void
    main(String[] consoleArguments)
    {
        Helper.appendTextToLogFile("");
        Helper.appendTextToLogFile("# Test Case A04/B05/C05/D04/E03/G03/H03: \"Checks in the HTML source code for not replaced Twig placeholders like {{ and }} on homepage.\"");
        Helper.appendTextToLogFile("");
        Helper.appendTextToLogFile("Steps for reproduce: ");
        
        WebDriver driver = Helper.getChromeWebDriver();

        /* Resize browser dimension to desktop monitor size. */
        driver.manage().window().setSize(new Dimension(1600, 900));

        /* ### */
        String[] urls = {
            "",
            "?routing=/products",
            "?routing=/products-by-mysql",
            "?routing=/quotes",
            "?routing=/project-statistics",
            "?routing=/impressum",
            "?routing=/search"
        };

        for (int indexForUrl = 0; indexForUrl < urls.length; indexForUrl++)
        {
            /* ### */
            String url = Helper.getBaseUrlForAutomatedTests() + urls[indexForUrl];

            try
            {
                Helper.appendTextToLogFile("* go to url: " + url);
                driver.get(url);
            }
            catch (Exception exception)
            {
                if (null != driver)
                {
                    driver.close();
                    driver.quit();
                }

                Helper.appendTextToLogFile("[ERROR] FrontendTest crashed!");
                System.exit(0);
            }

            /* Check if actual URL is equal to expected URL! */
            String currentUrl = driver.getCurrentUrl();
            if (!currentUrl.equals(url))
            {
                Helper.appendTextToLogFile("[ERROR] FrontendTest #4 stopped: Actual URL \"" + currentUrl + "\" is not like expected URL \"" + url + "\"!");

                if (null != driver)
                {
                    driver.close();
                    driver.quit();
                }

                System.exit(0);
            }

            /* Check HTTP status code! */
            LogEntries logEntries = driver.manage().logs().get(LogType.BROWSER);
            int statusCode = Helper.getHttpStatusCodeByBrowserLogs(logEntries, url, currentUrl);
            if (200 != statusCode)
            {
                Helper.appendTextToLogFile("[ERROR] FrontendTest #4 stopped: Wrong HTTP status code " + statusCode + " was found!");

                if (null != driver)
                {
                    driver.close();
                    driver.quit();
                }

                System.exit(0);
            }

            /* ### */
            Helper.appendTextToLogFile("* get the HTML source code from the current page");
            String currentHtmlSourceCode = driver.getPageSource();

            /* ### */
            String[] textsFromTwig = {"{{", "}}"};

            for (int i = 0; i <= textsFromTwig.length - 1; i++)
            {
                Helper.appendTextToLogFile("* check for the Twig placeholder " + textsFromTwig[i] + " in the fetched HTML source code");
                if (currentHtmlSourceCode.contains("{{"))
                {
                    Helper.appendTextToLogFile("[ERROR] Test Case A04/[...] stopped: " + textsFromTwig[i] + " as a not replaced placeholder was found!");
                    System.exit(0);
                }
            }
            
            /* ### */
            Helper.appendTextToLogFile("");
        }

        driver.close();
        driver.quit();
        
        System.exit(0);
    }
}
